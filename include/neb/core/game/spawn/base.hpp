#ifndef NEBULA_GAME_SPAWN_BASE_HPP
#define NEBULA_GAME_SPAWN_BASE_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/math/pose.hpp>
#include <neb/core/game/spawn/util/decl.hpp>

namespace neb { namespace core { namespace game { namespace spawn {

	class base: virtual public nc::itf::shared
	{

		public:
			typedef nc::game::spawn::util::parent parent_t;

			neb::core::pose		pose_;

			virtual void		init(parent_t * const & p);			
			virtual void		step(gal::etc::timestep const &);

	};


}}}}

#endif
