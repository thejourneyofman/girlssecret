#include <stdio.h>
#include <vector>
using namespace std;

#define N 7
typedef int MAT[N][N];

namespace doinit{
    MAT mat;
    void initArray(){
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mat[i][j] = i*N + j + 1;
    }
}

// A sample greedy solution for Q1.
class PathTracer {
public:
    PathTracer( vector<int> mysrc, vector<int> mydec )
        : src(mysrc), dec(mydec)
    {
    }

    void trace_all_paths() {
        vector<int> path;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited[i][j] = false;
        recursive_tracing(src, path);
        printf(" Total Prob is %f\n", total_prob);
    }

    void printMat() {
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                printf(" %d", mat[i][j]);
            printf("\n");
        }
    }

private:
    const MAT &mat = doinit::mat;
    vector<int> src;
    vector<int> dec;
    bool visited[N][N];
    double total_prob = 0;

    void recursive_tracing(vector<int> src, vector<int> path) {
        visited[src.at(0)][src.at(1)] = true;
        path.push_back(mat[src.at(0)][src.at(1)]);
        // If cell arrives at the destination, do the calculation and print.
        if (src == dec) {
            total_prob += do_calculate(path);
        } else {
            vector< vector<int> > allcand = candidates(src.at(0), src.at(1));
            for (int i = 0; i < allcand.size(); i++) {
                if (visited[allcand[i].at(0)][allcand[i].at(1)] == false ) {
                    recursive_tracing({allcand[i].at(0), allcand[i].at(1)}, path);
                }
            }
        }
        // Mark the current cell as unvisited and remove it from the path.
        visited[src.at(0)][src.at(1)] = false;
        path.front();
    }

    vector< vector<int> > candidates(int x, int y) {
        vector< vector<int> > result;
        vector<int> dX = { 0,  0, -1,  1};
        vector<int> dY = { 1, -1,  0 , 0};

        for (int i = 0; i < dX.size(); i++) {
            int new_x = x + dX[i];
            int new_y = y + dY[i];
            if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
                result.push_back({new_x, new_y});
        }
        return (result);
    }

  double do_calculate(vector<int> path) {
      double prob = 1.0;
      for (int i = 0; i < path.size() - 1; i++) {
          printf(" %d", path[i]);
          // Cells in the corners.
          if (path[i] == 1 || path[i] == N || path[i] == N*N - N - 1) {
            prob *= 0.5;
          }
          // Cells on the boundaries.
          else if (((path[i] -1)/N) == 0 || (path[i] -N) <= 0 || (path[i]/N) == 0 || (path[i]- N*(N-1)) > 0){
            prob /= 3;
          }
          else{
            prob *= 0.25;
          }
      }
      printf(" Each Prob is %.25lf\n", prob);
      return (prob);
  }
};


int main()
{
	doinit::initArray();
    vector<int> mysrc{ 2,1 };
    vector<int> mydec{ 6,6 };
    PathTracer myPT(mysrc, mydec);
    myPT.trace_all_paths();
	return 0;
}
