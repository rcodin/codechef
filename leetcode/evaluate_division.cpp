class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
		this->equations = equations;
		this->values = values;
        //nominator_hash;
        // unordered_map<string, vector<int>> numerator_hash;
        //denominator_hash;
        // unordered_map<string, vector<int>> denominator_hash;
		build_hash();
        //build graph using nominator and denominator hash
        //build_graph(); already built using numerator hash
        //run the queries with dfs
		for (vector<string> query: queries) {
            visited.clear();
            if (((numerator_hash.find(query[0]) == numerator_hash.end())
                 &&(denominator_hash.find(query[0]) == denominator_hash.end())) ||
               ((numerator_hash.find(query[1]) == numerator_hash.end())
                 &&(denominator_hash.find(query[1]) == denominator_hash.end()))) {
                ans.push_back(-1.0);
            }
            else if (query[0] == query[1]) {
					ans.push_back(1.0);
			}
			//do dfs
			else {
				double val = 1.0;
				if(do_dfs(query[0], query[1], val))
                    ans.push_back(val);
                else
                    ans.push_back(-1.0);
			}
		}
        return ans;
    }
private:
	vector<vector<string>> equations;
	vector<double> values;
	unordered_map<string, vector<int>> numerator_hash;
	unordered_map<string, vector<int>> denominator_hash;
	unordered_map<string, int> visited;
    void build_hash() {
        for (int i = 0; i < equations.size(); i++) {
			vector<string> elem = equations[i];
            // cout<<elem[0]<<" "<<elem[1]<<endl;
			if (numerator_hash.find(elem[0]) == numerator_hash.end()) {
					vector<int> temp;
					temp.push_back(i);
					numerator_hash[elem[0]] = temp;
			}
			else {
					numerator_hash[elem[0]].push_back(i);
			}

			if (denominator_hash.find(elem[1]) == denominator_hash.end()) {
					vector<int> temp;
					temp.push_back(i);
					denominator_hash[elem[1]] = temp;
			}
			else {
					denominator_hash[elem[1]].push_back(i);
			}
		}
    }
	bool do_dfs(string st, string en, double &ans) {
		if (st == en)
			return true;
		if(visited.find(st) != visited.end()){
			if (visited[st] == 1)
					return false;
		}
		double temp = ans;
		visited[st] = 1;
        if (numerator_hash.find(st) != numerator_hash.end()) {
            for (int i = 0; i < numerator_hash[st].size(); i++) {
                int idx = numerator_hash[st][i];
                string en_next = equations[idx][1];
                ans *= values[idx];
                if (do_dfs(en_next, en, ans))
                        return true;
                ans = temp;
            }
        }
        if (denominator_hash.find(st) != denominator_hash.end()) {
            for (int i = 0; i < denominator_hash[st].size(); i++) {
                int idx = denominator_hash[st][i];
                string en_next = equations[idx][0];
                // cout<<ans<<endl;
                ans = ans * (((double)1.0)/values[idx]);
                // cout<<values[idx]<<endl;
                if (do_dfs(en_next, en, ans))
                        return true;
                ans = temp;
            }
        }
		return false;
	}
};

