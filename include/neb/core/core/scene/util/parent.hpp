#ifndef NEBULA_SCENE_UTIL_PARENT_HH
#define NEBULA_SCENE_UTIL_PARENT_HH

#include <gal/stl/map.hpp>

#include <neb/core/itf/Pose.hh>
#include <neb/core/util/parent.hpp>
#include <neb/core/core/scene/base.hpp>

namespace neb { namespace core { namespace core { namespace scene { namespace util {
	/** @brief parent
	*/
	class parent:
		virtual public nc::util::parent<nc::core::scene::base, parent>,
		virtual public nc::itf::Pose
	{
		public:
	};
}}}}}

#endif

