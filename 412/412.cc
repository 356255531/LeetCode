class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;

        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[0].size();j++) {
                if (grid[i][j]) {
                    if ((i - 1 > 0) && (j - 1 > 0)) {
                        if (!grid[i - 1][j - 1]) {
                            count++;
                        }
                    }
                    else {
                        count++;
                    }
                    if ((i + 1 < grid.size() - 1) && (j - 1 > 0)) {
                        if (!grid[i + 1][j - 1]) {
                            count++;
                        }
                    }
                    else {
                        count++;
                    }
                    if ((i - 1 > 0) && (j + 1 < grid[0].size())) {
                        if (!grid[i - 1][j + 1]) {
                            count++;
                        }
                    }
                    else {
                        count++;
                    }
                    if (i + 1 < grid.size() - 1 && j + 1 < grid[0].size()) {
                        if (!grid[i + 1][j + 1]) {
                            count++;
                        }
                    }
                    else {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};