/**
 * Date:  2016
 * Author: Rafael Muñoz Salinas
 * Description: demo application of DBoW3
 * License: see the LICENSE.txt file
 */

#define USE_CONTRIB
#define OPENCV_VERSION_3

#include <iostream>
#include <vector>
#include <string.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iomanip>

// DBoW3
#include "DBoW3.h"

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#ifdef USE_CONTRIB
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
#endif
#include "DescManip.h"

using namespace DBoW3;
using namespace std;

const int NUM_KLUSTER = 10;
const int NUM_LAYER = 5;
const int num_training = 99;
const int num_test = 91;

string g_descriptor = "brisk";
string corr_matrix_output = "";
ScoringType g_score;

const string dataset_name = "New College";

// configurable parameters
const string train_img_dir_path = "/media/dongwonshin/Ubuntu Data/Datasets/Places365/Large_images/val_large/images";
const string test_img_dir_path = "/media/dongwonshin/Ubuntu Data/Datasets/FAB-MAP/Image Data/"+ dataset_name +" ManualLC/images";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// extended surf gives 128-dimensional vectors
const bool EXTENDED_SURF = false;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void wait()
{
    cout << endl << "Press enter to continue" << endl;
    getchar();
}

// functions
vector<string> getFileNames (string dir)
{
	vector<string> file_lists;

	DIR *dp;
	struct dirent *ep;
	dp = opendir (dir.c_str());

	if (dp != NULL)
	{
		while (ep = readdir (dp)){
			if (strcmp(ep->d_name, ".") && strcmp(ep->d_name, "..") && strcmp(ep->d_name, "temp"))
				file_lists.push_back(dir + "/"+ ep->d_name);
		}

		(void) closedir (dp);
	}
	else
		perror ("Couldn't open the directory");

	sort(file_lists.begin(),file_lists.end());

	return file_lists;
}

void strCurrentTime(ostringstream& ss)
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	ss << (now->tm_year + 1900) << '-'
		 << setfill('0') << setw(2) << (now->tm_mon + 1) << '-'
		 << setfill('0') << setw(2) << now->tm_mday << '-'
		 << setfill('0') << setw(2) << now->tm_hour << '-'
		 << setfill('0') << setw(2) << now->tm_min << '-'
		 << setfill('0') << setw(2) << now->tm_sec;
}

struct stat st = {0};
void makeLogDir(ostringstream& ss)
{
	string log_dir = "result/" + ss.str();

	if (stat(log_dir.c_str(), &st) == -1) {
 	   mkdir(log_dir.c_str(), 0700);
	}
}

string scoringTypeToString(ScoringType score)
{
	if (score == L1_NORM)
		return string("L1_NORM");
	else if (score == L2_NORM)
		return string("L2_NORM");
	else if (score == CHI_SQUARE)
		return string("CHI_SQUARE");
	else if (score == KL)
		return string("KL");
	else if (score == BHATTACHARYYA)
		return string("BHATTACHARYYA");
	else if (score == DOT_PRODUCT)
		return string("DOT_PRODUCT");
}

void resultLogOrganization()
{
	ostringstream cur_time_str;
	strCurrentTime(cur_time_str);
	makeLogDir(cur_time_str);

	corr_matrix_output = "result/" + cur_time_str.str() + "/corr_matrix.txt";
	cout << corr_matrix_output.c_str() << endl;

	ofstream ofs(("result/"+cur_time_str.str()+"/parameters.cfg").c_str());

	ofs << "[General]" << endl;
	ofs << "Method = "  << g_descriptor << endl;
	ofs << "Dataset = " << dataset_name << endl;
	ofs << "Scoring type = " << scoringTypeToString(g_score) << endl;
}

vector<string> readImagePaths(int argc,char **argv,int start){
    vector<string> paths;
    for(int i=start;i<argc;i++)
    	paths.push_back(argv[i]);

    return paths;
}
vector<string> readImagePaths(int from, int to, bool isTraining){

	vector<string> paths;
	if (isTraining)
	{
		paths = getFileNames(train_img_dir_path.c_str());
		paths.erase(paths.begin()+100, paths.end());
	}
	else
		paths = getFileNames(test_img_dir_path.c_str());

	return paths;
//
//	for(int i = from; i <= to; ++i)
//	{
//		char filename[1024];
//		if (isTraining)
//			sprintf(filename, "/media/dongwonshin/Ubuntu Data/Datasets/Places365/Large_images/val_large/images/Places365_val_%08d.jpg", i);
//		else
//			sprintf(filename, "/media/dongwonshin/Ubuntu Data/Datasets/FAB-MAP/Image Data/City Centre/images/%04d.jpg", i);
//
////		printf("%s\n", filename);
//		paths.push_back(filename);
//	}
//	return paths;
}

vector< cv::Mat  >  loadFeatures( std::vector<string> path_to_images,string descriptor="") throw (std::exception){
    //select detector
    cv::Ptr<cv::Feature2D> fdetector;
    if (descriptor=="orb")        fdetector=cv::ORB::create();
    else if (descriptor=="brisk") fdetector=cv::BRISK::create();
    else if (descriptor=="akaze") fdetector=cv::AKAZE::create();
    else if(descriptor=="surf" )  fdetector=cv::xfeatures2d::SURF::create(300, 4, 2, EXTENDED_SURF);

    else throw std::runtime_error("Invalid descriptor");
    assert(!descriptor.empty());
    vector<cv::Mat>    features;

//    cout << "Extracting   features..." << endl;

    for(size_t i = 0; i < path_to_images.size(); ++i)
    {
        vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        cout<<"reading image: "<<path_to_images[i]<<endl;
        cv::Mat image = cv::imread(path_to_images[i], 0);
        if(image.empty())throw std::runtime_error("Could not open image"+path_to_images[i]);
//        cout<<"extracting features"<<endl;
        fdetector->detectAndCompute(image, cv::Mat(), keypoints, descriptors);

        int limited_num = 30000;
        if (descriptors.size().height < limited_num)
        {
        	features.push_back(descriptors);
        	cout << descriptors.size() << endl;
        }
        else
        {
			cv::Rect r(0,0,fdetector->descriptorSize(),limited_num);
			cv::Mat limited_desc = descriptors(r).clone();
			cout << limited_desc.size() << endl;
			features.push_back(limited_desc);
        }
//        cout<<"done detecting features"<<endl;
    }

    return features;
}

// ----------------------------------------------------------------------------

void testVocCreation(string descriptor, const vector<cv::Mat> &training_features, const vector<cv::Mat> &test_features)
{
    // branching factor and depth levels
    const int k = NUM_KLUSTER;
    const int L = NUM_LAYER;
    const WeightingType weight = TF_IDF;
    const ScoringType score = g_score;

    DBoW3::Vocabulary voc(k, L, weight, score);

    cout << "Creating a small " << k << "^" << L << " vocabulary..." << endl;
    voc.create(training_features);
    cout << "... done!" << endl;

    cout << "Vocabulary information: " << endl << voc << endl << endl;

    string file_name = corr_matrix_output;
    FILE *fp = fopen(file_name.c_str(),"wt");
    // lets do something with this vocabulary
    cout << "Matching images against themselves (0 low, 1 high): " << endl;
    BowVector v1, v2;
    for(int i = 0; i < test_features.size(); i++)
	{
		double max_score = 0.0;
		int most_related_idx = 0;

		voc.transform(test_features[i], v1);
		for(int j = 0; j < test_features.size(); j++)
		{
			if (i <= j) {
				voc.transform(test_features[j], v2);

				double score = voc.score(v1, v2);
				fprintf(fp, "%lf ", score);

				if (max_score < score && score < 0.99)
				{
					max_score = score;
					most_related_idx = j+1;
				}
			}
			else
			{
				fprintf(fp, "%lf ", 0);
			}
		}
		fprintf(fp, "\n");
		printf("current_idx=%d, max_score=%lf, most_related_idx=%d\n", i+1, max_score, most_related_idx);
	}
    fclose(fp);

//    for(size_t i = 0; i < features.size(); i++)
//    {
//        voc.transform(features[i], v1);
//        for(size_t j = 0; j < features.size(); j++)
//        {
//            voc.transform(features[j], v2);
//
//            double score = voc.score(v1, v2);
//            cout << "Image " << i << " vs Image " << j << ": " << score << endl;
//        }
//    }

//    // save the vocabulary to disk
//    cout << endl << "Saving vocabulary..." << endl;
//    voc.save("small_voc.yml.gz");
//    cout << "Done" << endl;
}

////// ----------------------------------------------------------------------------

void testDatabase(const  vector<cv::Mat > &features)
{
    cout << "Creating a small database..." << endl;

    // load the vocabulary from disk
    Vocabulary voc("small_voc.yml.gz");

    Database db(voc, false, 0); // false = do not use direct index
    // (so ignore the last param)
    // The direct index is useful if we want to retrieve the features that
    // belong to some vocabulary node.
    // db creates a copy of the vocabulary, we may get rid of "voc" now

    // add images to the database
    for(size_t i = 0; i < features.size(); i++)
        db.add(features[i]);

    cout << "... done!" << endl;

    cout << "Database information: " << endl << db << endl;

    // and query the database
    cout << "Querying the database: " << endl;

    QueryResults ret;
    for(size_t i = 0; i < features.size(); i++)
    {
        db.query(features[i], ret, 4);

        // ret[0] is always the same image in this case, because we added it to the
        // database. ret[1] is the second best match.

        cout << "Searching for Image " << i << ". " << ret << endl;
    }

    cout << endl;

    // we can save the database. The created file includes the vocabulary
    // and the entries added
    cout << "Saving database..." << endl;
    db.save("small_db.yml.gz");
    cout << "... done!" << endl;

    // once saved, we can load it again
    cout << "Retrieving database once again..." << endl;
    Database db2("small_db.yml.gz");
    cout << "... done! This is: " << endl << db2 << endl;
}


// ----------------------------------------------------------------------------

int main(int argc,char **argv)
{
    try{
        string descriptor= g_descriptor;
        cout << descriptor << endl;

        resultLogOrganization();

        auto training_images=readImagePaths(1,num_training,true);
        vector< cv::Mat> training_features = loadFeatures(training_images,descriptor);

        auto test_images=readImagePaths(1,num_test,false);
        vector< cv::Mat> test_features = loadFeatures(test_images,descriptor);

        testVocCreation(descriptor, training_features, test_features);

    }catch(std::exception &ex){
        cerr<<ex.what()<<endl;
    }

    return 0;
}
