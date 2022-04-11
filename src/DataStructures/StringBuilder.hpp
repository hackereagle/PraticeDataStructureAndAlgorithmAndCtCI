#pragma once
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "memory.h"

class StringBuilder
{
public:
    StringBuilder()
    {}

    
    StringBuilder() 
    {}

    void Append(std::string str)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        mData.push_back(str);
        this->mLen = this->mLen + str.size();
    }

    std::string String()
    {
        char* ret = new char[this->mLen + 1];
        int index = 0;
        for(std::string str: this->mData){
            int len = str.size();
            memcpy(ret + index, str.c_str(), len);
            index = index + len;
        }
        *(ret + this->mLen) = '\0';
        this->mRet = std::string(ret);
        delete[] ret;
    }

private:
    size_t mLen = 0;
    std::list<std::string> mData;
    std::string mRet = "";
};