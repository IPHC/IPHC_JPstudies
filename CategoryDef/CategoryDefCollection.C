#include "CategoryDefCollection.h"


CategoryDefCollection::CategoryDefCollection() :  TObject()
{
  

}


void CategoryDefCollection::Copy(TObject &obj) const 
{  
  TObject::Copy(obj);
  ((CategoryDefCollection&)obj).ListOfCategory = ListOfCategory;
  
  
  
}
