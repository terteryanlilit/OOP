#include "slideApplication.h"

#include "core_slideCollection.h"
#include "core_slideEditor.h"
#include "gui_slideMainWindow.h"

void SlideApplication::init(GUI::SlideMainWindow* pMainWindow)
{
	m_pSlideMainWindow = pMainWindow;
	
	m_pSlideCollection = std::make_shared<Core::SlideCollection>();
	
	// Add a new blank slide to the collection
	m_pSlideCollection->addSlide(std::make_shared<Core::Slide>(), true);
	
	m_pSlideEditor = std::make_shared<Core::SlideEditor>(m_pSlideCollection);

	if (m_pSlideMainWindow)
	{
		GUI::SlideCanvas* pSlideCanvas = m_pSlideMainWindow->getSlideCanvas();
		if (pSlideCanvas)
			pSlideCanvas->setSlide(m_pSlideCollection->getActiveSlide());

		GUI::SlideCollectionView* pSlideCollectionView = m_pSlideMainWindow->getSlideCollectionView();
		if (pSlideCollectionView)
			pSlideCollectionView->setSlideCollection(m_pSlideCollection);

		m_pSlideMainWindow->setSlideEditor(m_pSlideEditor);
	}
}