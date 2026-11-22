
#include "settings/sections/settings_pudgikkgram_hub.h"
#include "settings/sections/settings_main.h"
#include "lang/lang_keys.h"

#include "settings/settings_common_session.h"
#include "settings/settings_builder.h"

#include "ui/wrap/vertical_layout.h"

#include "styles/style_menu_icons.h"

namespace Settings {
namespace {

using namespace Builder;

class PudgikkgramHub : public Section<PudgikkgramHub> {
public:
	PudgikkgramHub(
		QWidget *parent,
		not_null<Window::SessionController*> controller);

	[[nodiscard]] rpl::producer<QString> title() override;

private:
	void setupContent();
};

const auto kMeta = BuildHelper({
	.id = PudgikkgramHub::Id(),
	.parentId = MainId(),
	.title = &tr::lng_settings_advanced,
	.icon = &st::menuIconManage,
}, [](SectionBuilder &builder) {
	// Здесь позже появятся настройки Pudgikkgram Hub.
});

const SectionBuildMethod kPudgikkgramHubSection = kMeta.build;

PudgikkgramHub::PudgikkgramHub(
	QWidget *parent,
	not_null<Window::SessionController*> controller)
: Section(parent, controller) {
	setupContent();
}

rpl::producer<QString> PudgikkgramHub::title() {
	return rpl::single(u"Pudgikkgram Hub"_q);
}

void PudgikkgramHub::setupContent() {
	const auto content = Ui::CreateChild<Ui::VerticalLayout>(this);
	build(content, kPudgikkgramHubSection);
	Ui::ResizeFitChild(this, content);
}

} // namespace

Type PudgikkgramHubId() {
	return PudgikkgramHub::Id();
}

} // namespace Settings
