#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue; // Ignore empty tokens and current directory markers
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Go up one directory level
                }
            } else {
                stack.push_back(token); // Valid directory name
            }
        }
        
        // Reconstruct the canonical path
        string result = "";
        for (const auto& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};