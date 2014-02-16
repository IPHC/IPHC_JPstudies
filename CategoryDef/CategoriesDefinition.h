#ifndef CategoriesDefinition_H
#define CategoriesDefinition_H



#include "CategoryDef.h"
#include <vector>
#include <TStyle.h>
#include <TCanvas.h>
#include <TObject.h>
#include <TH1F.h>


class CategoriesDefinition : public TObject {
  public :
   CategoriesDefinition() {
    
  };
  ~CategoriesDefinition() {};
  std::vector<CategoryDef > CategoryList();
  ClassDef(CategoriesDefinition, 1)
};


#endif
