#include <iostream>
#include <fstream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/max.hpp>
#include <boost/accumulators/statistics/min.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <boost/cstdint.hpp>

namespace ba = boost::accumulators;


int main()
{
	//Configurations
	const unsigned long xdim = 48000;
	const unsigned long ydim = 31500;

	const double pix_size = 100.0;

	const std::string in_data_file("/Volumes/WD2TB/cms/conus/output/v7/tsfilter_v2/maxent_conus_agb_2005_v7_tsfilter_v2.int")
	const std::string in_category_file("/Volumes/WD2TB/cms/conus/state/CONUS_us_state_100m_albers.byt")
	const std::string in_lc_file("/Volumes/WD2TB/nlcd/conus/NLCD_2006_conus_L48_20190424.byt")
	
	ba::int16_t *data_row = new ba::int16_t[xdim];
	ba::uint8_t *category_row = new ba::uint8_t[xdim];
	ba::uint8_t *lc_row = new ba::uint8_t[xdim];


	//Boost Accumulator sets
	ba::accumulator_set<double, ba::features<ba::tag::mean,ba::tag::median,ba::tag::count,ba::tag::sum,ba::tag::skewness,ba::tag::kurtosis,ba::tag::variance> > acc_forest;
	ba::accumulator_set<double, ba::features<ba::tag::mean,ba::tag::median,ba::tag::count,ba::tag::sum,ba::tag::skewness,ba::tag::kurtosis,ba::tag::variance> > acc_shurbland;
	ba::accumulator_set<double, ba::features<ba::tag::mean,ba::tag::median,ba::tag::count,ba::tag::sum,ba::tag::skewness,ba::tag::kurtosis,ba::tag::variance> > acc_wetland;


	//Open input image file, category file, and landcover file
	std::ifstream in_data_stream(in_data_file, std::ios::binary|std::ios::in);
	std::ifstream in_category_stream(in_category_file, std::ios::binary|std::ios::in);
	std::ifstream in_lc_stream(in_lc_file, std::ios::binary|std::ios::in);

	for (int row=0; row<ydim; row++) {
		//Read a row from data file
		in_data_stream.read((char *) data_row, xdim*sizeof(std::int16_t));

		//Read a row from category file
		in_category_stream.read((char *) category_row, xdim*sizeof(std::uint8_t));

		//Read a row from landcover file
		in_lc_stream.read((char *) lc_row, xdim*sizeof(std::uint8_t));

		//Iterate through pixels in the row and add to accumulators
		for (int i=0; i<xdim; i++) {
			if (lc_row[i] == 41) || (lc_row[i] == 42) || (lc_row[i] == 43) {
				//Forest
			}

			if (lc_row[i] == 51) || (lc_row[i] == 52) {
				//Shrubland

			}

			if (lc_row[i] == 90) || (lc_row[i] == 95) {
				//Wetlands

			}

		}


	}
