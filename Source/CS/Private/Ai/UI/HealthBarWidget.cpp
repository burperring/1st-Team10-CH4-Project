
#include "ai/UI/HealthBarWidget.h"

void UHealthBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHealthBarWidget::SetBarValuePercent(float const value)
{
	HealthProgressBar -> SetPercent(value);
}
