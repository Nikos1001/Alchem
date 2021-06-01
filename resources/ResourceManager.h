
#pragma once

#include "../types.h"
#include "../renderer/Texture.h"

namespace Alchem {
    class Runtime;
}

namespace AlchemResource {

    struct ResourceHandle {
        ui32 index;
        ui32 uid;
    };

    template<class T>
    class ResourceManager {
    public:
        explicit ResourceManager(Alchem::Runtime* rt) {
            runtime = rt;
            currUid = 0;
        }

        ResourceHandle GetHandle(const string& identifier) {
            if(resourceCache.find(identifier) == resourceCache.end()) {
                T *resource = GetByStringIdentifier(identifier);
                resources.push_back(std::make_unique<T>(*resource));
                uids.push_back(currUid);
                resourceCache[identifier] = {(ui32)(resources.size() - 1), currUid};
                currUid++;
            }
            ResourceHandle handle = resourceCache[identifier];
            if(uids[handle.index] != handle.uid) {
                // TODO
            }
            return handle;
        }

        T *Get(ResourceHandle handle) {
            if(handle.uid != uids[handle.index])
                return nullptr;
            return resources[handle.index].get();
        }

        T *Get(const string& identifier) {
            return Get(GetHandle(identifier));
        }

        Alchem::Runtime* runtime;
    private:
        virtual T *GetByStringIdentifier(const string& identifier) {
            return nullptr;
        }

        map<string, ResourceHandle> resourceCache;
        array<ptr<T>> resources;
        array<ui32> uids;
        ui32 currUid;
    };

}

