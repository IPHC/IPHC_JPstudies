#ifndef CategoryDefCollection_H
#define CategoryDefCollection_H

#include "TH1F.h"
#include <string>
#include <TObject.h>
#include <vector>
#include "CategoryDef.h"

class CategoryDefCollection  : public TObject {
  public :
    
    CategoryDefCollection() ;
  ~CategoryDefCollection() {};
  
  void Copy(TObject &catdef) const;
  std::vector<CategoryDef > ListOfCategory;
  
  ClassDef(CategoryDefCollection, 1)
};


#endif
