from django.shortcuts import render, redirect, HttpResponse 
from .models import Shows 
from django.contrib import messages


# Create your views here.
def index(request):
    context ={
        "all_shows": Shows.objects.all()
    }
    return render(request,'index.html', context)

def NewShow(request):
    return render(request,'new_show.html')

def EditShow(request, show_id):
    context = {
        "show": Shows.objects.get(id= show_id)
    }
    return render(request,'edit_show.html', context)

def DescribeShow(request, show_id):    
    context = {
        "show": Shows.objects.get(id= show_id)
    }
    return render(request,'describe_show.html', context)

def delete(request):
    return render(request,'describe_show.html')

def create(request):

    errors = Shows.objects.basic_validator(request.POST)

    if len(errors) > 0:
        for key, value in errors.items():
            messages.error(request, value)
        return redirect('/shows/new')
    else:
        Shows.objects.create(
            title = request.POST['title'],
            network = request.POST['network'],
            release_date = request.POST['release_date'],
            description = request.POST['description'],
        )
        return redirect("/")

def Update(request, show_id):

    errors = Shows.objects.basic_validator(request.POST)

    if len(errors) > 0:
        for key, value in errors.items():
            messages.error(request, value)
        return redirect('/shows/'+ str(show_id) +'/edit')
    else:
        #instance
        edited_show = Shows.objects.get(id = show_id)
        #Change Value
        edited_show.title = request.POST['title']
        edited_show.network = request.POST['network']
        edited_show.release_date = request.POST['release_date']
        edited_show.description = request.POST['description']

        edited_show.save()
        return redirect("/shows")

def delete(request, show_id):
    delete_show = Shows.objects.get(id = show_id)

    delete_show.delete()
    return redirect("/shows")