#ifndef __U_RAW_SEQ__
#define __U_RAW_SEQ__

//edit audacity truck.
//export this as a non-compressed 8-bit PCM *.raw.
//cat *.raw | xxd -i
//output example:
//  0x00, 0x05, 0x06, 0x0b, 0x0f, 0x14, 0x19, 0x21, 0x28, 0x2e, 0x35, 0x3c, ...
//import this as char[]

#include <vector>

class raw_seq {
public:
	void set_data(const char* d, int size, int realtime_duration_sec);
	void start_seq();
	//from -1.0f to 1.0f
	double get_current_value();

private:
	std::vector<char> data_;
	int duration_ms_;
	long long t_start_;
};

#endif
