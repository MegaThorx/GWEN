/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Anim.h"
#include "gwen/Utility.h"
#include <math.h>

using namespace gwen;

#ifndef GWEN_NO_ANIMATION

static gwen::Anim::Animation::List	g_Animations;
static gwen::Anim::Animation::ChildList g_AnimationsListed;

void gwen::Anim::Add( gwen::Controls::Base* control, Animation* animation )
{
	animation->m_Control = control;
	g_Animations[control].push_back( animation );
}

void gwen::Anim::Cancel( gwen::Controls::Base* control )
{
	/* cannot use std::list iterator with algoryhtmns based on pointers
	struct AnimDeletePredicate
	{
		AnimDeletePredicate( gwen::Controls::Base* control )
		{
			this->control = control;
		}

		bool operator() ( gwen::Anim::Animation* anim )
		{
			return anim->m_Control == control;
		}

		gwen::Controls::Base* control;
	};

	std::remove_if ( g_Animations.begin(), g_Animations.end(), AnimDeletePredicate( control ) );
	*/
	gwen::Anim::Animation::List::iterator iAnimations;

	if ( ( iAnimations = g_Animations.find( control ) ) != g_Animations.end() )
	{
		gwen::Anim::Animation::ChildList & ChildAnimationsForControl = iAnimations->second;
		gwen::Anim::Animation::ChildList::iterator iAnimationChild = ChildAnimationsForControl.begin();

		if ( iAnimationChild != ChildAnimationsForControl.end() )
		{
			do
			{
				delete( *iAnimationChild );
			}
			while ( ++iAnimationChild != ChildAnimationsForControl.end() );
		}

		g_Animations.erase( iAnimations );
	}
}

void gwen::Anim::Think()
{
	gwen::Anim::Animation::List::iterator it = g_Animations.begin();

	if ( it != g_Animations.end() )
	{
		gwen::Anim::Animation::ChildList::iterator itChild;
		gwen::Anim::Animation* anim;

		do
		{
			if ( ( itChild = it->second.begin() ) != it->second.end() )
			{
				do
				{
					anim = *itChild;
					anim->Think();

					if ( anim->Finished() )
					{
						itChild = it->second.erase( itChild );
						delete anim;
					}
					else
					{
						++itChild;
					}
				}
				while ( itChild != it->second.end() );
			}
		}
		while ( ++it != g_Animations.end() );
	}
}

gwen::Anim::TimedAnimation::TimedAnimation( float fLength, float fDelay, float fEase )
{
	m_fStart = Platform::GetTimeInSeconds() + fDelay;
	m_fEnd = m_fStart + fLength;
	m_fEase = fEase;
	m_bStarted = false;
	m_bFinished = false;
}

float GetEased( float fTime, float fEase )
{
	// Ease in and Out if ease is < 0
	if ( fEase < 0 )
	{ return -fTime / 2 * ( cos( 3.14159f * fTime ) - 1 ); }

	return pow( fTime, fEase );
}

void gwen::Anim::TimedAnimation::Think()
{
	if ( m_bFinished ) { return; }

	float fCurrent = Platform::GetTimeInSeconds();
	float fSecondsIn = fCurrent - m_fStart;

	if ( fSecondsIn < 0.0f ) { return; }

	if ( !m_bStarted )
	{
		m_bStarted = true;
		OnStart();
	}

	float fDelta = fSecondsIn / ( m_fEnd - m_fStart );

	if ( fDelta < 0.0f ) { fDelta = 0.0f; }

	if ( fDelta > 1.0f ) { fDelta = 1.0f; }

	float fEased = GetEased( fDelta, m_fEase );
	Run( fEased );

	if ( fDelta == 1.0f )
	{
		m_bFinished = true;
		OnFinish();
	}
}

bool gwen::Anim::TimedAnimation::Finished()
{
	return m_bFinished;
}

#endif