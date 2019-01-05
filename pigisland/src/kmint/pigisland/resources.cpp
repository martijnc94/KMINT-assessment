#include "kmint/pigisland/resources.hpp"
#include "resources.hpp"


namespace kmint {
namespace pigisland {
namespace {
constexpr const char *graph_description = R"graph(32 24 32
resources/pigisland.png
W 1 1
1 1 1
2 1 1
3 1 1
R 1 4
L 0 0
S 0 0
K 1 1

LLLLLLWW1WWWWRWWWWWWWWWWRWWWLLLL
LLLLLLLLLWWWWRWWWWWWWWWWRWWWLLLL
LLLLLLWWWWWWRRWWWWWWWWWWRRWWWWWL
WWWWWWWWWWWRRWWWWWWWWWWWWRRWWW2L
WWWWWWWWWWRRWWWWWWWWWWWWWRRRWWWW
WRRRRRRRRRRWWWWWWWWWWWWWWWRRWWWW
WWRRRRRRRRWWWWWWWWWWWWWWWRRRRWWW
WRRWWWRWWWWWWWWWWWWWWWWWWWWRRRRW
WWWWWWWWWWWWWLLLLLWWWWWWWWWWWWWW
WWWWWWWWWWWWWLLLLLLWWWWWWWWWWWWW
WWWWWWWWWWWWWLLLLLLWWWWWWWWWWWWW
WWWWWWWWWWWWWLLLLLLLWWWWWWWWWWWW
WWWWWWWWWWWWWLLLLLLLWWWWWWWWWWWW
WWWWWWWWWWWWWWLLLLLWWWWWWRRRRRWW
WWWWWWWWWWWWWWWWWWWWWWWWRRWRRRRW
WWWWWRRRWWWWWWWWWWWWWWWWRRRWWWWW
WWWWWWWWRWWWWWWWWWWWWWWWWRWWWWWW
WWLLLLLWWRWWWWWWWWWWWWWRRWWWL3WW
WWLLLLLWWRRWWWWWWWWWWWRRWWWWLWLL
WWLLLLLWWWRRWWWWWWWWWWRWWWLLLLLL
SSLLLLWWWWWRRRWWWWWWWWWWWLLLLLLL
SSLLLLWWWWWWWRRRRWWWWWWWWLLLLLLL
SSWWWWWWWWWWWWWWWWWWWWWWWLLLLLLL
KWWWWWWWWWWWWWWWWWWWWWWWWLLLLLLL
)graph";
}

map::map map() { return map::read_map(graph_description); }

graphics::image shark_image() { return graphics::image{"resources/shark.png"}; }
graphics::image pig_image() { return graphics::image{"resources/pig.png"}; }

graphics::image boat_image() { return graphics::image{"resources/boat.png"}; }

std::vector<Obstacle *> makeObstacles(play::stage &s)
{
    auto v = std::vector<Obstacle*>();

    // First island.
    for (auto y = 0; y < 3; ++y) {
        if (y == 0) {
            // First row.
			for (auto x = 0; x < 6; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
			for (auto x = 29; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
        } else if (y == 1) {
            for (auto x = 0; x < 9; x++) {
                auto loc = math::vector2d{(float)16 + (x * 32), (float)16 + (y * 32)};

                auto &b = s.build_actor<Obstacle>(loc);
                v.emplace_back(&b);
            }
			for (auto x = 29; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
        }
		else if (y == 2) {
			for (auto x = 0; x < 6; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
			for (auto x = 31; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
		} else if (y == 3) {
			for (auto x = 31; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
		}
    }

	for (int y = 17; y < 23; y++) {
		if (y < 22) {
			for (auto x = 2; x < 7; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
			for (auto x = 28; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
		}
		else {
			for (auto x = 2; x < 6; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
			for (auto x = 25; x < 33; x++) {
				auto loc = math::vector2d{ (float)16 + (x * 32), (float)16 + (y * 32) };

				auto &b = s.build_actor<Obstacle>(loc);
				v.emplace_back(&b);
			}
		}
	}

    return v;
}

} // namespace pigisland

} // namespace kmint
