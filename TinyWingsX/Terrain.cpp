//
//  Terrain.cpp
//  TinyWingsX
//
//  Created by jie ding on 12/20/12.
//
//

#include "Terrain.h"

using namespace cocos2d;

Terrain::Terrain()
{
    m_pSprite = NULL;
    m_fOffsetX = 0.0f;
    CCSize sz = CCDirector::sharedDirector()->getWinSize();
    m_fScreenWidth = sz.width;
    m_fScreenHeight = sz.height;
    m_nTextureSize = 0;
    m_nHillKeyPoints = 0;
    m_nHillVertices = 0;
    m_nFromkeyPoint = 0;
    m_nToKeyPoint = 0;
    srand(time(NULL));
    
}

Terrain::~Terrain()
{
    
}

bool Terrain::init()
{
    this->generateHillKeyPoints();
    this->generateBorderVertices();
    return true;
}

void Terrain::setOffsetX(float var)
{
    if(m_fOffsetX == var)
        return;
    
    m_fOffsetX = var;
}

float Terrain::getOffsetX()
{
    return m_fOffsetX;
}

void Terrain::generateHillKeyPoints()
{
    m_nHillKeyPoints = 0;
    float x, y, dx, dy, ny;

    m_aHillKeyPoints[0] = (ccVertex2F){-m_fScreenWidth/4, m_fScreenHeight*3/4};
    m_aHillKeyPoints[1] = (ccVertex2F){0, m_fScreenHeight/2};
    
    int mindx = 160, rangedx = 80;
    int mindy = 60, rangedy = 60;
    float maxH = m_fScreenHeight;
    float minH = 20;
    
    x = 0;
    y = m_fScreenHeight/2;
    int sign = -1;
    for(int i = 2; i < kMaxHillKeyPoints - 1; i++)
    {
        dx = mindx + rand() % rangedx;
        x += dx;
        dy = mindy + rand() % rangedy;
        y += sign * dy;
        
        if(y > maxH)
            y = maxH;
        else if(y < minH)
            y = minH;
        
        sign *= -1;
        m_aHillKeyPoints[i] = (ccVertex2F){x, y};
    }
    
    x += mindx + rangedx;
    y = 0;
    m_aHillKeyPoints[kMaxHillKeyPoints-1] = (ccVertex2F){x, y};
    
}

void Terrain::draw()
{
//    for(int i = 0; i < kMaxHillKeyPoints; i++)
//    {
//        CCPoint pt1 = CCPoint(
//        ccDrawLine(const cocos2d::CCPoint &origin, const cocos2d::CCPoint &destination);
//    }
}

void Terrain::generateBorderVertices()
{
    
}

