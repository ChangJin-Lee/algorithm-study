#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int node, int &count) {
    visited[node] = true;
    count++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, count);
        }
    }
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    adj.resize(n);
    visited.resize(n, false);

    for (auto &pair : astronaut) {
        adj[pair[0]].push_back(pair[1]);
        adj[pair[1]].push_back(pair[0]);
    }

    vector<int> componentSizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, count);
            componentSizes.push_back(count);
        }
    }

    long long totalPairs = (long long)n * (n - 1) / 2;
    long long sameCountryPairs = 0;

    for (int size : componentSizes) {
        sameCountryPairs += (long long)size * (size - 1) / 2;
    }

    return totalPairs - sameCountryPairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
