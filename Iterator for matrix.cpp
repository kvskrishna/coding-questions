/*

iterator for a matrix

*/

class MatrixIter
{
 
public:

  MatrixIter (vector<vector<int>>& matrix) : vecvec(matrix), ni(0), nj(0), Inited(false){}
 
  bool hasNext()
  {
    if (!vecvec.empty() && !vecvec[0].empty()) return true;
 
    int i,j;
    return prob(i,j);
  }
 
  int getVal() { return vecvec[ni][nj]; }
 
  void next()
  {
    if (!inited) {
    
        inited = true;
        if (!vecvec.empty() && !vecvec[0].empty()) return;
    }
 
    prob(ni, nj);
  }
 
private:

  bool prob(int& i, int& j) //by reference
  {
    i = ni;
    j = nj;
     
    if (i >= vecvec.size()) return false;
     
    if (i < vecvec.size() && j < vecvec[i].size()-1) { //col++
    
        j++;
        return true;
    }
 
    i++; //row ++
    
    for(; i < vecvec.size(); i++) {
    
        if (!vecvec[i].empty()) break;
    }
 
    if (i == vecvec.size()) return false;
 
    j = 0; //new row
 
    return true;
  }

  vector<vector<int>>& vecvec;
  bool inited; 
  int ni;
  int nj;


};
