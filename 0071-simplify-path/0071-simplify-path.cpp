class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string dir;
        stringstream ss(path);
        
        // Split the path by '/' and process each part
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                // Skip empty parts and the current directory (".")
                continue;
            } else if (dir == "..") {
                // Pop the stack for ".." (move to parent directory) if the stack is not empty
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // For valid directory names, push them onto the stack
                stack.push_back(dir);
            }
        }
        
        // Rebuild the canonical path
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i != stack.size() - 1) {
                result += "/";
            }
        }
        
        return result;
    }
};
