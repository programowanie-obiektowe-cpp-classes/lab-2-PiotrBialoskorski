#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource(new Resource()) {}

    ResourceManager(const ResourceManager& zasob)
        : resource(new Resource(*zasob.resource)) {} 

    ResourceManager& operator=(const ResourceManager& zasob) 
    {
        if (this != &zasob) {
            delete resource;
            resource = new Resource(*zasob.resource);
        }
        return *this;
    }

    double get() { return resource->get(); }

    ResourceManager(ResourceManager&& zasob)
        : resource(std::move(zasob.resource)) {} 

    ResourceManager& operator=(ResourceManager&& zasob)
    {
        if (this != &zasob) {
            delete resource;
            resource = std::move(zasob.resource);
        }
        return *this;
    }

    ~ResourceManager() { delete resource; } 

    private:
        Resource* resource;
};
