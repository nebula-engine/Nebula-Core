#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/Two.hpp>

#include <neb/fnd/plug/gfx/environ/Base.hpp>

typedef neb::fnd::environ::Two THIS;

void		THIS::init(parent_t * const & parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	G::make_object<THIS, int>(app->_M_graphics_plugin, neb::fnd::plug::gfx::environ::type::TWO);
}
void		THIS::release()
{
}

