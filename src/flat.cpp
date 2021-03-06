#include "integrator.h"
#include "scene.h"

class FlatIntegrator : public Integrator {
public:
    FlatIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, const Ray &ray) const {
        /** TODO : Find the surface that is visible in the requested direction
                   Return its ambiant color */
        Hit h = Hit();
        scene->intersect(ray, h);

        if (h.foundIntersection())
        {
            Color3f diffuse = h.shape()->material()->diffuseColor(Vector2f(0.0f));
            //Color3f ambient = h.shape()->material()->ambientColor();
            return diffuse;
        }
        else {
            return scene->backgroundColor();
        }

        //return Color3f(0.f);

    }

    std::string toString() const {
        return "FlatIntegrator[]";
    }
};

REGISTER_CLASS(FlatIntegrator, "flat")
