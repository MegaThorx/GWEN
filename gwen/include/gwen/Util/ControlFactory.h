
#pragma once

#include "gwen/Gwen.h"
#include "ControlFactory.h"

namespace gwen
{
	namespace ControlFactory
	{
		class Base;
		typedef std::list< ControlFactory::Base* > List;

		List & GetList();
		ControlFactory::Base* Find( const gwen::String & name );
		Controls::Base* Clone( Controls::Base* pEnt, ControlFactory::Base* pFactory );

		class Property
		{
			public:

				typedef std::list<Property*> List;

				virtual gwen::String			Name() = 0;
				virtual gwen::String			Description() = 0;

				virtual gwen::UnicodeString		GetValue( gwen::Controls::Base* ctrl ) = 0;
				virtual void					SetValue( gwen::Controls::Base* ctrl, const gwen::UnicodeString & str ) = 0;

				virtual int						OptionNum() { return 0; }
				virtual gwen::UnicodeString		OptionGet( int i ) { return L"";}

				virtual int						NumCount() { return 0; };
				virtual gwen::String			NumName( int i ) { return "unknown"; };
				virtual float					NumGet( gwen::Controls::Base* ctrl, int i ) { return 0.0f; };
				virtual void					NumSet( gwen::Controls::Base* ctrl, int i, float f ) {};

				inline void NumSet( gwen::Controls::Base* ctrl, const gwen::String & str, float f )
				{
					for ( int i = 0; i < NumCount(); i++ )
					{
						if ( NumName( i ) == str ) { NumSet( ctrl, i, f ); }
					}
				};
		};

		class PropertyBool : public Property
		{
			public:

				static const gwen::UnicodeString		True;
				static const gwen::UnicodeString		False;

				virtual int						OptionNum() { return 2; }
				virtual gwen::UnicodeString		OptionGet( int i ) { if ( i == 0 ) { return False; } return True; }
		};

		class Base
		{
			public:

				Base();

				virtual gwen::String Name() = 0;
				virtual gwen::String BaseName() = 0;

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent ) = 0;

				Base* GetBaseFactory();
				void AddProperty( Property* pProp );

				Property* GetProperty( const gwen::String & name );
				void SetControlValue( gwen::Controls::Base* ctrl, const gwen::String & name, const gwen::UnicodeString & str );

				const Property::List & Properties() { return m_Properties; }

				// Called when the control is drag and dropped onto the parent, even when just moving in the designer
				virtual void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child,
									   const gwen::Point & pos );

				// Called when creating the control - param might be empty
				virtual void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child,
									   int iPage = 0 );

				// Called when a child is clicked on in an editor
				virtual bool ChildTouched( gwen::Controls::Base* ctrl, gwen::Controls::Base* pChildControl ) { return false; };


				//
				// If a control is parented to a control with multiple sections, or pages
				// these functions are used to store which page they're on - on the child control
				//
				virtual void SetParentPage( gwen::Controls::Base* ctrl, int i );
				virtual int GetParentPage( gwen::Controls::Base* ctrl );

			protected:

				Property::List	m_Properties;
		};

	}

}

#define GWEN_CONTROL_FACTORY_CONSTRUCTOR( ThisName, BaseName )\
	typedef BaseName BaseClass;\
	typedef ThisName ThisClass;\
	ThisName() : BaseClass()

#define GWEN_CONTROL_FACTORY( ThisName ) \
    void GWENCONTROLFACTORY##ThisName()\
    {\
        new ThisName();\
    }

#define DECLARE_GWEN_CONTROL_FACTORY( ThisName )\
    extern void GWENCONTROLFACTORY##ThisName();\
    GWENCONTROLFACTORY##ThisName();

#define GWEN_CONTROL_FACTORY_PROPERTY( _name_, _description_ )\
	public:\
	gwen::String Name() { return #_name_; }\
	gwen::String Description() { return _description_; }


