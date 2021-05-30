import { Component, OnInit } from '@angular/core';

import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { SocialAuthService, GoogleLoginProvider, SocialUser } from 'angularx-social-login';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})

export class AppComponent implements OnInit {

  loginForm: FormGroup;
  socialUser: SocialUser;
  isLoggedin: boolean; 
  isRegistered: boolean; 
  resp: any;
  respreg: any;
  showSpinner: boolean;
  firstName: string;
  lastName: string;
  phoneNumber: number;
  isStudent: boolean;
  showMainPage: boolean;
  registerToken: string;
  showSpinnerForRegistration: boolean;
  registrationSuccessful: boolean;
  registrationFailed: boolean;
  
  constructor(
    private formBuilder: FormBuilder, 
    private socialAuthService: SocialAuthService,
    private http: HttpClient
  ) { this.isLoggedin = false;
     this.showSpinner = false;
     this.showSpinnerForRegistration= false;
     this.registrationSuccessful = false;
   }

  ngOnInit() {
    this.loginForm = this.formBuilder.group({
      email: ['', Validators.required],
      password: ['', Validators.required]
    });    
    
    this.socialAuthService.authState.subscribe((user) => {
      this.socialUser = user;
      this.isLoggedin = (user != null);
      if(this.isLoggedin === true) {
        console.log("loginwithsmartbus called");
        this.loginWithSmartBus();
      }
      console.log(this.socialUser);
    });
  }

  loginWithSmartBus() {
    this.showSpinner = true;
    var formData: any = new FormData();
    formData.append("accessToken", this.socialUser.authToken);
    
  
    this.http.post('http://localhost:4200/api', formData).subscribe(
      (response) => {

        console.log(response);
        this.resp = response;
        console.log(this.resp.registered);
        this.registerToken = this.resp.token;
        if(this.resp.registered === true) {
          
          setTimeout(()=>{ this.showSpinner = false; this.isRegistered = true; this.registrationFailed = false;
            this.registrationSuccessful = false;  this.showMainPage = true;}, 4000)
          
        }
        else {
          setTimeout(()=>{ this.showSpinner = false; this.isRegistered = false; }, 4000)
        }
      } ,
      (error) => console.log(error)
    )
    
    
  
    
  }

  loginWithGoogle(): void {
    this.showSpinner = true;
    this.socialAuthService.signIn(GoogleLoginProvider.PROVIDER_ID);
  }

  logOut(): void {
    this.socialAuthService.signOut();
  }

  onClickSubmit(data: any) {
    this.showSpinnerForRegistration = true;
    console.log(data.firstName);
    console.log(data.lastName);
    console.log(data.phoneNumber);
    console.log(data.isStudent);
    if(data.isStudent === 'Yes') {
      this.isStudent=  true;
    } else {
      this.isStudent = false;
    }

    const headers = { 'Authorization': 'Token '+this.registerToken };
    console.log(this.registerToken);
    const body = { firstName: data.firstName, lastName: data.lastName, isStudent: this.isStudent, phoneNo: data.phoneNumber };
    this.http.post('http://localhost:4200/reg', body, { headers }).subscribe(response => {
        this.respreg = response;
        console.log(this.resp);
        if(this.respreg.response === 'User has been successfully created') {
          setTimeout(()=>{ this.showSpinnerForRegistration = false; this.isRegistered = true; this.registrationSuccessful = true; }, 4000)
        } else {
          setTimeout(()=>{ this.showSpinnerForRegistration = false; this.registrationFailed = true; }, 4000)
        }
    });
  }

}


