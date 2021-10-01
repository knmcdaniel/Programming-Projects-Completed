from django.urls import path     
from . import views

urlpatterns = [
    path('', views.index),
    path('login', views.login),
    path('logout', views.logout),
    path('register', views.register),
    path('quotes', views.main_landing),
    path('quotes/create', views.create_quote),
    path('quotes/<int:quote_id>/edit', views.edit),
    path('quotes/<int:quote_id>/update', views.update),
    path('quotes/<int:quote_id>/destory', views.destroy),
    path('quotes/users/<int:user_id>', views.view_quotes),
] 