#include <string.h>
#include <dirent.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include "DBoW3.h"
#include "BowVector.h"

#include <boost/property_tree/ini_parser.hpp>

using namespace std;
using namespace DBoW3;

class DW_Config {

private:
	// configurable parameters
	string train_img_dir_path = "";
	string test_img_dir_path = "";

	string corr_matrix_output = "";

	int train_set_num = 100;
	int test_set_num = 1000;

	string eval_method;
	string eval_dataset; //City Centre, New College
	ScoringType score_type = L1_NORM; // L1_NORM, L2_NORM, CHI_SQUARE, KL, BHATTACHARYYA, DOT_PRODUCT
	WeightingType weighting_type = TF_IDF;
	int cluster_center;
	int depth_level;

	string result_dir = "";


public:
	DW_Config() {
		// soft coded configs
		boost::property_tree::ptree pt;
		boost::property_tree::ini_parser::read_ini("input_config.ini", pt);

		string _eval_method = pt.get<string>("Experiment_parameters.eval_method");
		string _eval_dataset = pt.get<string>("Experiment_parameters.eval_dataset");
		string _scoring_type = pt.get<string>("Experiment_parameters.scoring_type");
		int _cluster_center = pt.get<int>("Experiment_parameters.cluster_center");
		int _depth_level = pt.get<int>("Experiment_parameters.depth_level");
		string _result_dir = pt.get<string>("Experiment_parameters.result_dir");

		eval_method = _eval_method;
		eval_dataset = _eval_dataset;

		score_type = L1_NORM; // TO DO:
		cluster_center = _cluster_center;
		depth_level = _depth_level;

		result_dir = _result_dir;

		train_img_dir_path = "/media/dongwonshin/Ubuntu Data/Datasets/Places365/Large_images/val_large (36500)/images";
		test_img_dir_path = "/media/dongwonshin/Ubuntu Data/Datasets/FAB-MAP/Image Data/"+ eval_dataset +" ManualLC/images";

		printConfig();
	}
	~DW_Config() {
		printConfig();
	}

	void printConfig()
	{

		cout << "=========================================" << endl
			 << "eval_method = " << eval_method.c_str() << endl
			 << "eval_dataset = " << eval_dataset.c_str() << endl
			 << "scoring_type = " << score_type << endl
			 << "cluster_center = " << cluster_center << endl
			 << "depth_level = " << depth_level << endl
			 << "=========================================" << endl;
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
		string log_dir = result_dir + "/" + ss.str();

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

		corr_matrix_output = result_dir + "/" + cur_time_str.str() + "/corr_matrix.txt";

		ofstream ofs((result_dir + "/" +cur_time_str.str()+"/output_config.ini").c_str());
		ofs << "[Experiment_parameters]" << endl;
		ofs << "exp_method = " << eval_method << endl;
		ofs << "eval_dataset = " << eval_dataset << endl;
		ofs << "scoring_type = " << scoringTypeToString(score_type) << endl;
		ofs << "cluster_center = " << cluster_center << endl;
		ofs << "depth_level = " << depth_level << endl;
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

	/////////////////////////////////////// Getter & Setter

	string getEvalMethod() {return eval_method;}
	string getEvalDataset() {return eval_dataset;}

	ScoringType getScoringType() {return score_type;}
	WeightingType getWeightingType() {return weighting_type;}
	int getClusterCenterNum() {return cluster_center;}
	int getDepthLevelNum() {return depth_level;}

	string getTrainImgDirPath() {return train_img_dir_path;}
	string getTestImgDirPath() {return test_img_dir_path;}

	int getTrainSetNum() {return train_set_num;}
	int getTestSetNum() {return test_set_num;}

	string getCorrMatrixOutput() {return corr_matrix_output;}

};
