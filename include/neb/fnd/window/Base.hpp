#ifndef NEB_CORE_WINDOW_BASE_HPP
#define NEB_CORE_WINDOW_BASE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/input/source.hpp>
#include <neb/fnd/input/callback.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/context/util/decl.hpp>
#include <neb/fnd/context/util/Parent.hpp>
#include <neb/fnd/window/util/decl.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/window/Base.hpp>

namespace neb { namespace fnd { namespace window {

	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::window::util::Parent>,
		virtual public neb::fnd::context::util::Parent,
		virtual public neb::fnd::input::source,
		virtual public neb::fnd::input::callback,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::window::Base>
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::window::Base> G;
			typedef neb::fnd::window::util::Parent parent_t;
			typedef neb::fnd::util::parent<neb::fnd::context::Base, neb::fnd::context::util::Parent> contexts;
			
			//base();
			virtual ~Base();
			virtual void		init(parent_t * const & p);
			virtual void		release();
			
			virtual glm::vec2	getCursorPosNDC();
			
			/** @name Main Loop @{ */
			virtual void		render();
			virtual void		step(gal::etc::timestep const & ts);
			/** @} */
			virtual void		resize();
			void		makeCurrent();

			
			void		callback_window_pos_fun(/*GLFWwindow*,*/int,int);
			void		callback_window_size_fun(/*GLFWwindow*,*/int,int);
			void		callback_window_close_fun(/*GLFWwindow**/);
			void		callback_window_refresh_fun(/*GLFWwindow**/);
			void		callback_mouse_button_fun(/*GLFWwindow*,*/int,int,int);
			void		callback_key_fun(/*GLFWwindow*,*/int,int,int,int);
			void		callbackCharFun(/*GLFWwindow*,*/unsigned int);
			void			print_screen();
			virtual int		get_width();
			virtual int		get_height();
			void			create_object_graphics();
			/*
			virtual std::weak_ptr<neb::fnd::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::fnd::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<neb::fnd::context::Window>	createContextWindow() = 0;
			virtual std::weak_ptr<neb::fnd::context::Window>	createContextVisDepth() = 0;
			*/

	};
}}}

#endif


