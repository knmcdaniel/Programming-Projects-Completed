from django.urls import path     
from . import views

urlpatterns = [
    path('', views.index),
    path('user', views.list_users),   #Just used for testing, can only access manually. Obviously not something you would put in production, it just helps me remember the fake emails I've made so I don't repeat them while testing. 
    path('login', views.login),
    path('logout', views.logout),
    path('register', views.register),
    path('<int:user_id>', views.user_landing),
    #path('create', views.create),
] 
