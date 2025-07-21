#include "core.h"

#include <random>
#include <sstream>
#include <iomanip>

// ================================= UTILITY FUNCTIONS START =========================
std::string generateUUID()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::stringstream ss;
    ss << std::hex;

    // Generate 32 random hex digits
    for (int i = 0; i < 8; i++)
        ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 4; i++)
        ss << dis(gen);
    ss << "-4"; // Version 4
    for (int i = 0; i < 3; i++)
        ss << dis(gen);
    ss << "-";
    ss << dis2(gen); // Variant bits (8, 9, A, or B)
    for (int i = 0; i < 3; i++)
        ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 12; i++)
        ss << dis(gen);

    return ss.str();
}
// ================================= UTILITY FUNCTIONS END ===========================
// ===================================================================================
// ================================= ENTITY CODE START ===============================
Entity::Entity()
{
    _id = generateUUID();
    addComponent(0); // Adding Mesh
    addComponent(1); // Adding Transform
}

// this overloaded constructor is for custom prefab Entities that will dictate what components should be/not be present in the initial creation of the object
Entity::Entity(bool *component_List, int total_No_of_Components)
{
    _id = generateUUID();
    for (int i = 0; i < total_No_of_Components; i++)
    {
        if (component_List[i] == true)
        {
            addComponent(i);
        }
    }
}

Component *Entity::getComponent(int component)
{
    switch (component)
    {
    case 0:
        return Mesh;
        break;
    case 1:
        return Transform;
        break;

    default:
        logger.log("Please choose a valid component id to retrieve");
        break;
    }

    return nullptr;
}

void Entity::addComponent(int component)
{
    switch (component)
    {
    case 0:
        Mesh = new component_Mesh;
        logger.log("Mesh Component Added");
        break;
    case 1:
        Transform = new component_Transform;
        logger.log("Transform Component Added");
        break;

    default:
        logger.log("Please choose a valid component id to add");
        break;
    }
}

void Entity::removeComponent(int component)
{
    switch (component)
    {
    case 0:
        delete Mesh;
        Mesh = nullptr;
        logger.log("Mesh Component Removed");
        break;
    case 1:
        delete Transform;
        Transform = nullptr;
        logger.log("Transform Component Removed");
        break;

    default:
        logger.log("Please choose a valid component id to remove");
        break;
    }
}

Entity::~Entity()
{
}
// ================================= ENTITY CODE END =================================
// ===================================================================================
// ================================= ECS CODE START ==================================

ECS::ECS() // Empty to pass "default constructor undefined" issue
{
}

ECS::ECS(FileManager *fileManager)
{
    logger.log("========================= [Entity Component System] Initializing:");

    // Startup tasks of the ECS when the Engine starts:
    this->fileManager = fileManager;
    logger.log("File Manager linked to ECS");

    logger.log("************************* [Entity Component System] Initialized\n");
}

int ECS::CreateEntity()
{
    Entity newEntity;
    ObjectList.push_back(newEntity);

    return 0;
}
int ECS::DestroyEntity()
{
    return 0;
}

ECS::~ECS()
{
}
// ================================= ECS CODE END ====================================