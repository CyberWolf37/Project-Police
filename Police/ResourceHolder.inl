
// Template to associate file path with ID
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    // Create and load ressource
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
            throw std::runtime_error("ResourceHolder::load - failed to load " + filename);

    // If loading successful, insert resource to map
    insertResource(id, std::move(resource));

}

// Template to associate file path with ID
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    // Create and load resource
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

    // If loading successful, insert resource to map
    insertResource(id, std::move(resource));
}

// Template to get a Resource
template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
}

// Template to get Resource Const!
template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
}

// Template to insert a resource in a map with is pair ID
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
    // Insert and check success
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}
