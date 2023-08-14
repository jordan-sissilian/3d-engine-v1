#include <iostream>
#include <dirent.h>
#include <string>
#include <vector>

std::vector<std::string> mfileLoader(char *name)
{
#define _path "./res/shape3d/"
	std::string path = _path;
	path.append(name);

#define nbExep 4
	const char dirExep[nbExep][10] = {".", "..", "texture", ".Ds_Store"};

	std::vector<std::string> obj;
	obj.push_back(name);

	struct dirent *entry = NULL;
	DIR *directory = 0;
	if ((directory = opendir(path.c_str())) == NULL)
		return (obj);
	int (*ptrStrcmp)(const char *, const char *) = &std::strcmp;
	for (int count = 1; (entry = readdir(directory)) != NULL; count = 0)
	{
		for (int i = 0; i < nbExep; i++)
			!!ptrStrcmp(entry->d_name, dirExep[i]) && count++;
		if (count == nbExep)
			obj.push_back(entry->d_name);
	}

	closedir(directory);
	return (obj);
}