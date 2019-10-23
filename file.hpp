#ifndef _file_h_
#define _file_h_

namespace util_file {

	std::string read(std::string file_location) {

		std::string content;
		std::ifstream handle;

		// Delay value :  Number of seconds before sampleing.
		handle.open(file_location, std::ios::out);
		content.assign( (std::istreambuf_iterator<char>(handle) ), (std::istreambuf_iterator<char>()) );
		handle.close();

		return content;
	}


	void write(std::string file_location, std::string content) {

		std::ofstream handle;
		handle.open(file_location, std::ios::in | std::ios::trunc);
		handle << content;
		handle.close();
	}


	void append(std::string file_location, std::string content) {

		std::ofstream handle;
		handle.open(file_location, std::ios::in | std::ios::app | std::ios::ate);
		handle << content << std::endl;
		handle.close();
	}


}

#endif