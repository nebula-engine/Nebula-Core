#ifndef NEBULA_UTIL_PARENT_HPP
#define NEBULA_UTIL_PARENT_HPP

#include <iostream>

#include <gal/stl/parent.hpp>
#include <gal/etc/timestep.hpp>

#include <neb/core/itf/shared.hpp>

namespace neb {
	namespace util {
		template<typename T> class parent: virtual public gal::stl::parent<T> {
			public:
				typedef gal::stl::parent<T>						gal_parent;
				typedef typename gal::stl::parent<T>::map_type				map_type;
				typedef typename map_type::iterator					iterator;
				typedef typename map_type::pointer					pointer;
				
				template<typename U, typename... CtorArgs> std::shared_ptr<U>		cii(CtorArgs... args) {
					auto u(sp::make_shared<U>(args...));
					
					insert(u);
					
					u->init();

					return u;
				}
				void		insert(std::shared_ptr< T > t)
				{
					gal_parent::insert(t);
				}
				void		init()
				{
					gal_parent::map_.for_each([&] (pointer p) {
							p->__init();
							});
				}
				void		release()
				{
					assert(0);
				//	gal_parent::map_.for_each([&] (pointer p) {
				//			p->release();
				//			});
				}
				void		step(gal::etc::timestep const & ts)
				{
					std::cout << __PRETTY_FUNCTION__ << std::endl;
					gal_parent::map_.for_each([&] (pointer p) {
							p->step(ts);
							});
				}

		};
	}
}

#endif
