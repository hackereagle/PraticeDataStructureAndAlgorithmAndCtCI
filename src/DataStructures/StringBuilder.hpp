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

    
    ~StringBuilder() 
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

    void Append(const char* str)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        std::string temp = std::string(str);
        mData.push_back(temp);
        this->mLen = this->mLen + temp.size();
    }

    void Append(int num)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        std::string str = std::to_string(num);
        mData.push_back(str);
        this->mLen = this->mLen + str.size();
    }

    void Append(double num)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        char temp[4096];
        sprintf(temp, "%f", num);
        std::string str = std::string(temp);
        mData.push_back(str);
        this->mLen = this->mLen + str.size();
    }

    void Append(float num)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        std::string str = std::to_string(num);
        mData.push_back(str);
        this->mLen = this->mLen + str.size();
    }

    void Append(bool _bool)
    {
        if(this->mRet != ""){
            this->mData.clear();
            this->mData.push_back(this->mRet);
            this->mRet = "";
        }
        
        std::string str = _bool ? "true" : "false";
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
        return this->mRet;
    }

private:
    size_t mLen = 0;
    std::list<std::string> mData;
    std::string mRet = "";
};