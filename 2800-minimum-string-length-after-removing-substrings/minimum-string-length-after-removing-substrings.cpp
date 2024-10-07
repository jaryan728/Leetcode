class Solution {
public:
    int minLength(string s) {
        size_t p1, p2;
        while (true) {
            p1 = s.find("AB");
            p2 = s.find("CD");

            if (p1 == std::string::npos && p2 == std::string::npos) {
                break;
            }

            if (p1 != std::string::npos) {
                s.erase(p1, 2);
            }

            p2 = s.find("CD");  
            if (p2 != std::string::npos) {
                s.erase(p2, 2);
            }
        }
        cout << s;
        return s.size();
    }
};