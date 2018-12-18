#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include <kmint/pigisland/domain/DNAString.h>
#include <kmint/pigisland/force/SteeringBehaviors.h>
#include <kmint/pigisland/force/EntityWithForce.h>
#include "kmint/play.hpp"
#include "boat.hpp"
#include "shark.hpp"

namespace kmint
{
    namespace pigisland
    {
        class pig : public EntityWithForce
        {
        public:
            explicit pig(math::vector2d location, boat &b, shark &s, std::vector<Obstacle> &obstacles);
            explicit pig(math::vector2d location, boat &b, shark &s, std::unique_ptr<DNAString> dna, std::vector<Obstacle> &obstacles);

            bool perceptive() const override { return true; }
            scalar range_of_perception() const override { return 30.0f; };
            scalar radius() const override { return 8.0f; }
            const ui::drawable &drawable() const override
            { return drawable_; }
            void move(math::vector2d delta)
            { location(location() + delta); }
            void act(delta_time dt) override;
            DNAString &getGeneticAttributes() const;
            boat &getBoat() const;
            shark &getShark() const;
        private:
            boat &boatActor;
            shark &sharkActor;
            play::image_drawable drawable_;
            std::unique_ptr<SteeringBehaviors> steeringBehaviors;
            std::unique_ptr<DNAString> geneticAttributes;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
