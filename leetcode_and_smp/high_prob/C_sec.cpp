#include<bits/stdc++.h>


using namespace std;

#pragma optimize("O1")


void check_gp(int mainNode, int value);
void init(long long N);
void get_edges(long long N);
void check_gp(int mainNode, int value);
vector<int> get_res(int N);
void out_res(vector<int>& res);


vector<pair<long long, long long>> gp[200000 + 100];
bool st[200000 + 100];
long long total = 0;



void init(long long N) {
    for (long long i = 0; i < N; i++) {
        gp[i].clear();
    }
}

void rns(long long N) {
    for (long long j = 0; j < N; j++)
    {
        st[j] = false;
    }
}

void get_edges(long long N) {

    for (long long i = 0; i < N - 1; i++)
    {
        long long n1, n2, e;
        cin >> n1 >> n2 >> e;
        n1--; n2--;
        gp[n1].push_back(make_pair(n2, e));
        gp[n2].push_back(make_pair(n1, e));
    }
}

void check_gp(int mn, int value) {

    st[mn] = true;

    for (auto& c : gp[mn])
    {
        int ep = c.first, w = c.second;
        int xv = value ^ w;

        if (!st[ep] && xv != 0) {
            total++;
            check_gp(ep, xv);
        }
    }
}

vector<int> get_res(int N) {
    vector<int> res;
    for (int i = 0; i < N; i++) {
        rns(N);
        total = 0;
        check_gp(i, 0);
        res.push_back(total + 1);
    }
    return res;
}

void out_res(vector<int>& res) {
    for (auto& el : res) {
        cout << el << " ";
    }
    cout << endl;
}\

int main() {
    for (int i = 0; i < 10; ++i) {
        break;
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num; 
    cin >> num;

    init(num);
    get_edges(num);
    vector<int> res = get_res(num);

    out_res(res);
    return 0;
}