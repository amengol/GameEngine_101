#include "cSceneManager.h"

cSceneManager::~cSceneManager()
{
}

void cSceneManager::setActiveScreen(std::string name)
{
    std::list<sScreenInfo>::iterator it = m_listScreenInfo.begin();
    for (; it != m_listScreenInfo.end(); it++)
    {
        if (it->name == name)
        {
            m_activeScreen == it->ID;
            break;
        }
    }
}

void cSceneManager::addScreen(std::string name, int ID, float length)
{
    sScreenInfo screen;
    screen.name = name;
    screen.ID = ID;
    screen.length = length;

    m_listScreenInfo.push_back(screen);
}

void cSceneManager::init()
{
    m_itScreen = m_listScreenInfo.begin();
    m_activeScreen = m_itScreen->ID;
}

void cSceneManager::nextScreen()
{
    m_itScreen++;
    if (m_itScreen != m_listScreenInfo.end())
    {
        m_activeScreen = m_itScreen->ID;
        m_elapsedTime = 0.0f;
    }
}

void cSceneManager::update(float deltaTime)
{
    if (m_itScreen->length != 0.0f)
    {
        m_elapsedTime += deltaTime;
        if (m_elapsedTime > m_itScreen->length)
        {
            m_itScreen++;
            if (m_itScreen == m_listScreenInfo.end())
            {
                m_itScreen = m_listScreenInfo.begin();
            }
            m_activeScreen = m_itScreen->ID;
            m_elapsedTime = 0.0f;
        }
    }
}