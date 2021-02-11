/*
 * Ransom Note
 * https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
 */ 
void checkMagazine(vector<string> magazine, vector<string> note) {
   //go one by one to magazine and insert it to hashmap
   map <string, int> mag;
   for(int i = 0; i < magazine.size(); i++) {
       if (mag.find(magazine[i]) != mag.end()){
           mag.find(magazine[i])->second++;    
       }
       mag.insert(pair<string, int>(magazine[i], 1));
   }
   for(int i = 0; i< note.size(); i++) {
       map<string,int>::iterator it = mag.find(note[i]);
       if (it == mag.end()) {
           cout << "No";
           return;
       } else {
           if (it->second == 0) {
               cout << "No";
               return;
           }
           it->second  = it->second - 1; 
       }
   }
   cout << "Yes";
}