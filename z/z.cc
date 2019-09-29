#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::vector<std::string::size_type> zBuild(const std::string& s) {
  std::string::size_type n = s.size(), l = 0, r = 0, i;
  // ignoring z[0]
  std::vector<std::string::size_type> z(n, 0);
  for(i = 1; i < n; ++i) {
    // check if interval between i and r is larger than z[i-l]
    // negative denotes i > r
    z[i] = std::max((size_t)0, std::min(z[i-l],r-i+1));
    while (i+z[i] < n && s[i+z[i]] == s[z[i]]) {
      l = i; r = i + z[i]; z[i] += 1;
    }
  }
  return z;
}

// can supply customized delimiter
std::vector<std::string::size_type> zMatch(const std::string& p, const std::string& t, const char& d = '$') {
  std::vector<std::string::size_type> z = zBuild(p+d+t), ans;
  for(std::string::size_type i = p.size(); i < z.size(); ++i) {
    if(z[i] == p.size()) { ans.push_back(i-p.size()-1); }
  }
  return ans;
}

int main() {
  std::string p, t;

  std::cout<< "Type pattern and string" << std::endl;
  std::cin >> p >> t;

  auto m = zMatch(p,t);

  std::cout<< "Found match at index(ex): " << std::endl;
  for(const auto& a:m) { std::cout<<a<<" "; }
  std::cout<<"\n";

  return 0;
}