/*
* You are asked to design a file system that allows you to create new paths and associate them with different values. 
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string "" and "/" are not.
Implement the FileSystem class:
bool createPath(string path, int value) Creates a new path and associates a value to it if possible and returns true. Returns false if the path already exists or its parent path doesn't exist.
int get(string path) Returns the value associated with path or returns -1 if the path doesn't exist.
* 
*/

/*
* SOLUTION:
* create tree structure to contain the file system
*/

#include <map>
#include <string>
#include <sstream>

using namespace std;
class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	bool create_path(string path, int value) {
		if (m_file_system_map.contains(path)) {
			return false;
		}
		stringstream path_stream(path);
		string parent;
		string parsed;
		while (getline(path_stream, parsed, m_seperator)) {
			parent += parsed;
			if (parent != path && !m_file_system_map.contains(parent)) {
				return false;
			}
			parent += m_seperator;
		}
		m_file_system_map[path] = value;
		return true;
	}
	int get_value(string path) {
		return m_file_system_map.contains(path) ? -1 : m_file_system_map[path];
	}
private:
	map<string, int> m_file_system_map;
	const char m_seperator = '/';
};