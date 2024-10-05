#ifndef _BOLT_WINDOW_PLUGIN_HXX_
#define _BOLT_WINDOW_PLUGIN_HXX_
#if defined(BOLT_PLUGINS)
#include "../library/ipc.h"
#include "../browser.hxx"
#include "../file_manager/directory.hxx"
#include "window_plugin_requests.hxx"

namespace Browser {
	struct PluginWindow: public Window, PluginRequestHandler {
		PluginWindow(CefRefPtr<Client> main_client, Details details, const char* url, CefRefPtr<FileManager::Directory> file_manager, BoltSocketType fd, uint64_t id, uint64_t plugin_id, bool show_devtools);
		bool IsDeleted() const;

		uint64_t WindowID() const override;
		uint64_t PluginID() const override;
		BoltSocketType ClientFD() const override;
		CefRefPtr<FileManager::FileManager> FileManager() const override;
		CefRefPtr<CefBrowser> Browser() const override;

		bool OnBeforePopup(
			CefRefPtr<CefBrowser>,
			CefRefPtr<CefFrame>,
			const CefString&,
			const CefString&,
			CefLifeSpanHandler::WindowOpenDisposition,
			bool,
			const CefPopupFeatures&,
			CefWindowInfo&,
			CefRefPtr<CefClient>&,
			CefBrowserSettings&,
			CefRefPtr<CefDictionaryValue>&,
			bool*
		) override;

		CefRefPtr<CefRequestHandler> GetRequestHandler() override;
		void NotifyClosed() override;

		private:
			uint64_t window_id;
			uint64_t plugin_id;
			CefRefPtr<FileManager::Directory> file_manager;
			BoltSocketType client_fd;
			bool deleted;
	};
}

#endif
#endif