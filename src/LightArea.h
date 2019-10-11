//lucia fuentes, fall 2019, hw2

#pragma once

#include "ILight.h"
#include "random.h"

/**
 * @brief Area light sourse class
 */
class CLightArea : public ILight
{
public:
	/**
	 * @brief Constructor
	 * @details The position and size of the area light source is given by the quadrangular luminous surface.
	 * This surface is defoned by 4 points in space: \b p1, \b p2, \b p3 and \b p4
	 * @param intensity The emission color and strength of the light source
	 * @param p0 The first point defining the quadrangular shape of the light source
	 * @param p1 The second point defining the quadrangular shape of the light source
	 * @param p2 The third point defining the quadrangular shape of the light source
	 * @param p3 The fourth point defining the quadrangular shape of the light source
	 */
	CLightArea(Vec3f intensity, Vec3f p0, Vec3f p1, Vec3f p2, Vec3f p3)
		: m_intensity(intensity)
		, m_p0(p0)
		, m_e1(p1 - p0)
		, m_e2(p3 - p0)
	{ 
		// --- PUT YOUR CODE HERE ---
        m_normal = 0; //variable to save cross product e1 e2
        m_normal = m_e1.cross(m_e2); //cross product m_e1 with m_e2
        
        m_area = 0; // variable to save normalization cross product
        m_area = norm(m_normal); //normalization of cross product
        
        m_normal = normalize(m_normal); //changing m_normal to normalization of itself
	}  

	virtual std::optional<Vec3f> Illuminate(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		return Vec3f();
	}

	Vec3f GetNormal(const Vec3f& position) const { return m_normal; }


private:
	Vec3f m_intensity;
	Vec3f m_p0;
	Vec3f m_e1;
	Vec3f m_e2;
	float m_area;
	Vec3f m_normal;
};
