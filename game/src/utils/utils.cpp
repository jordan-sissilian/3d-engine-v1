#include <iostream>
#include <dirent.h>
#include <string>
#include <vector>


std::vector<std::string> mfileLoader(char *name)
{
	DIR* directory = 0;
	struct dirent* entry;

	std::vector<std::string> obj;
	std::string path = "./res/shape3d/";
	int count = 0;

	path.append(name);
	obj.push_back(name);

	directory = opendir(path.c_str());
    if (directory != NULL) {
        while ((entry = readdir(directory)) != NULL)
			if (!!std::strcmp(entry->d_name, ".") && !!std::strcmp(entry->d_name, ".."))
				obj.push_back(entry->d_name);
		closedir(directory);
	}
	return (obj);
}