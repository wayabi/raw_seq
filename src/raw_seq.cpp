#include "raw_seq.h"
#include <string.h>
#include <chrono>
#include <ctime>

using namespace std::chrono;

void raw_seq::set_data(const char* d, int size, int realtime_duration_ms)
{
	duration_ms_ = realtime_duration_ms;
	data_.resize(size);
	memcpy(&data_[0], d, size);
	
}

void raw_seq::start_seq()
{
	t_start_ = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

double raw_seq::get_current_value()
{
	long long ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	int d = (int)(ms - t_start_);
	if(d < 0 || d >= duration_ms_){
		return -2;
	}
	return data_[data_.size() * d / duration_ms_] / (double)128;
}
