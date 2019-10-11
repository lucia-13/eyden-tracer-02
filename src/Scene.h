#pragma once

#include "ILight.h"
#include "Prim.h"
#include "CameraPerspective.h"

/**
 * @brief Scene class
 */
class CScene
{
public:
	/**
	 * @brief Constructor
	 * @param camera The reference to the camera
	 * @todo Background may be image
	 */
	CScene(Vec3f bgColor = RGB(0,0,0))
		: m_bgColor(bgColor)
		, m_pCamera(std::make_unique<CCameraPerspective>(Vec3f(0,0,8), Vec3f(0,0,-1), Vec3f(0,1,0), 60, Size(800, 600)))
	{}
  	~CScene(void) = default;
  
	/**
	 * @brief Adds a new primitive to the scene
	 * @param prim Pointer to the primitive
	 */
	void Add(const std::shared_ptr<CPrim> pPrim)
	{
		// --- PUT YOUR CODE HERE ---
        
           m_vpPrims.push_back(pPrim); //adding pPrim to vpPrims
	}
	/**
	 * @brief Adds a new light to the scene
	 * @param pLight Pointer to the light
	 */
	void Add(const std::shared_ptr<ILight> pLight)
	{
        m_vpLights.push_back(pLight); //adding lights to lights list
		// --- PUT YOUR CODE HERE ---
     
	}
  
	/**
	 * @brief Checks intersection of ray \b ray with all contained objects
	 * @param ray The ray
	 * @retval true If ray \b ray intersects any object
	 * @retval false otherwise
	 */
	bool Intersect(Ray& ray) const
	{
        long int max = m_vpPrims.size();
        for (int j = 0; j < max; j++) {
            if (m_vpPrims[j]->Intersect(ray)) {
                return true;
            } else{
                continue;
            }
            
        }
		// --- PUT YOUR CODE HERE ---
		return false;
	}

	/**
	 * find occluder
	 */
	bool Occluded(Ray& ray)
	{
        bool reval = Intersect(ray);
        return reval; //returns boolean stating wether ray intersecyts
		
	}

	/**
	 trace the given ray and shade it and
	 return the color of the shaded ray
	 */
	Vec3f RayTrace(Ray& ray) const
	{
        
		// --- PUT YOUR CODE HERE ---
        
        Vec3f colpix;
        colpix = m_bgColor;
        
        int max = 0;
        max = m_vpPrims.size();
        for (int j = 0; j < max; j++) {
            if (m_vpPrims[j]->Intersect(ray)) {
                colpix = (ray.hit->getShader()->Shade(ray));
            }
        }
        return colpix;
	}


public:
	std::unique_ptr<CCameraPerspective>		m_pCamera;
	std::vector<std::shared_ptr<ILight>>	m_vpLights;						///< lights
	
private:
	Vec3f									m_bgColor	= RGB(0, 0, 0);    	///< background color
	std::vector<std::shared_ptr<CPrim>> 	m_vpPrims;						///< primitives
};
