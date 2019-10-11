#pragma once

#include "ILight.h"

/**
 * @brief Point light source class
 */
class CLightPoint : public ILight
{
public:
	/**
	 * @brief Constructor
	 * @param position The position (origin) of the light source
	 * @param intensity The emission color and strength of the light source
	 */
	CLightPoint(Vec3f intensity, Vec3f position)
		: m_intensity(intensity)
		, m_position(position)
	{} 
	virtual ~CLightPoint(void) = default;

    virtual std::optional<Vec3f> Illuminate(Ray& ray) override{
  
        Vec3f vec1;
        
        for (int j = 0; j < 3; j++)
        {
            float idr;
            
             idr = (((ray.org[j] + ray.t) * ray.dir[j]) - m_position[i]);
            
            vec1[j] = m_intensity[j] / (idr * idr);
        }
        return Vec3f;
              // --- PUT YOUR CODE HERE ---
    }


private:
	Vec3f m_intensity; ///< emission (red, green, blue)
	Vec3f m_position;  ///< The light source origin
};
