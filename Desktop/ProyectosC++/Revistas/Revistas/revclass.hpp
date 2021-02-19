//
//  revclass.hpp
//  Revistas
//
//  Created by Victor Serrano Reyes on 30/12/19.
//  Copyright © 2019 Victor Serrano Reyes. All rights reserved.
//

#ifndef revclass_hpp
#define revclass_hpp

#include <stdio.h>
#include <string>

class Ceditorial{
private:
    std::string name;
    int canti;
public:
    Ceditorial();
    ~Ceditorial();
    void CapturaGeneral();
    void CapturaTodasRevistas();
    void ImprimeTodasRevistas();
};
#endif /* revclass_hpp */
