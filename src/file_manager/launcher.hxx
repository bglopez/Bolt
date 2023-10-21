#ifndef _A_BOLT_FILE_MANAGER_LAUNCHER_HXX_
#define _A_BOLT_FILE_MANAGER_LAUNCHER_HXX_
#include "../file_manager.hxx"

#include <algorithm>
#include <map>
#include <string.h>

// the matching cxx file is auto-generated by cmake based on the contents of the html directory

namespace FileManager {
	class Launcher: public FileManager {
		std::map<const char*, File> files;
		public:
			Launcher();

			File get(std::string_view path) const override {
				auto it = std::find_if(
					this->files.begin(),
					this->files.end(),
					[&path](const auto& e) { return strncmp(e.first, path.data(), path.size()) == 0 && e.first[path.size()] == '\0'; }
				);
				return (it == this->files.end()) ? File { .contents = nullptr } : it->second;
			}
	};
}

#endif