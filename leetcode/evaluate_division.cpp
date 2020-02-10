class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        //nominator_hash;
        unordered_map<char, vector<int>> numerator_hash;
        //denominator_hash;
        unordered_map<char, vector<int>> denominator_hash;
        //build graph using nominator and denominator hash
        build_graph();
        //run the queries with dfs
		for (vector<string> query: queries) {
		
		}
        return ans;
    }
private:
    void build_hash(vector<vector<string>>& equations, unordered_map<char,
						vector<int>> &numerator_hash, unordered_map<vector<int>>> &denominator_hash) {
        for (int i = 0; i < equations.size(); i++) {
			vector<string> elem = equations[i];
			if (numerator_hash.find(elem[0]) == numerator_hash.end()) {
					vector<int> temp;
					temp.push_back(i);
					numerator_hash[elem[0]] = temp;
			}
			else {
					numerator_hash[elem[0]].push_back(i);
			}

			if (denominator_hash.find(elem[1]) == numerator_hash.end()) {
					vector<int> temp;
					temp.push_back(i);
					denominator_hash[elem[1]] = temp;
			}
			else {
					denominator_hash[elem[1]].push_back(i);
			}
		}
    }
};
