#include <kmint/pigisland/actor/Obstacle.h>
#include <iostream>
#include "kmint/main.hpp" // voor de main loop
#include "kmint/pigisland/actor/boat.hpp"
#include "kmint/pigisland/actor/pig.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/actor/shark.hpp"
#include "kmint/pigisland/algorithm/Astar.h"
#include "kmint/play.hpp"
#include "kmint/ui.hpp"

using namespace kmint;
using namespace pigisland;

int main()
{
    // een app object is nodig om
    ui::app app{};

    //  maak een venster aan
    ui::window window{app.create_window({1024, 768}, "hello")};

    // maak een podium aan
    play::stage s{};

    auto map = pigisland::map();
    auto obstacles = makeObstacles(s);
    s.build_actor<Obstacle>(math::vector2d{100.0f, 100.0f});
    s.build_actor<play::background>(math::size(1024, 768), graphics::image{map.background_image()});
    s.build_actor<play::map_actor>(math::vector2d{0.f, 0.f}, map.graph());
    std::unique_ptr<Farm> farm = std::make_unique<Farm>(s);
    auto &boat = s.build_actor<pigisland::boat>(map.graph());
    auto &shark = s.build_actor<pigisland::shark>(map.graph(), *farm, boat);

    std::vector<pig *> pigs;
    for (int i = 0; i < 100; ++i) {
        auto &pig = s.build_actor<pigisland::pig>(math::vector2d(i * 10.0f, i * 6.0f), boat, shark, obstacles);
        pigs.push_back(&pig);
    }

    // Maak een event_source aan (hieruit kun je alle events halen, zoals
    // toetsaanslagen)
    ui::events::event_source event_source{};

    // main_loop stuurt alle actors aan.
    main_loop(s, window, [&](delta_time dt, loop_controls &ctl) {
        // gebruik dt om te kijken hoeveel tijd versterken is
        // sinds de vorige keer dat deze lambda werd aangeroepen
        // loop controls is een object met eigenschappen die je kunt gebruiken om de
        // main-loop aan te sturen.

        for (ui::events::event &e : event_source) {
            // event heeft een methode handle_quit die controleert
            // of de gebruiker de applicatie wilt sluiten, en zo ja
            // de meegegeven functie (of lambda) aanroept om met het
            // bijbehorende quit_event
            //
            e.handle_quit([&ctl](ui::events::quit_event qe) { ctl.quit = true; });
        }
    });
}
