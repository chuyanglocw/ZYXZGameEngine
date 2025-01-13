#ifndef __RESOURCE_HPP__
#define __RESOURCE_HPP__

#include <unordered_map>

namespace ZYXZ
{

template <typename _Key, typename _Value>
class Resource{
public:
    Resource(){}
    ~Resource(){
        clear();
    }
    void add(_Key key, _Value value){
        resourceMap[key] = value;
    }
    _Value get(_Key key){
        return resourceMap[key];
    }
    void remove(_Key key){
        resourceMap.erase(key);
    }
    void clear(){
        if (!resourceMap.empty()) resourceMap.clear();
    }
    bool has(_Key key){
        return resourceMap.find(key) != resourceMap.end();
    }
    bool empty(){
        return resourceMap.empty();
    }
    int size(){
        return resourceMap.size();
    }
    std::unordered_map<_Key, _Value> getMap(){
        return resourceMap;
    }
private:
    std::unordered_map<_Key, _Value> resourceMap;
};



} // namespace ZYXZ

#endif // ! __RESOURCE_HPP__